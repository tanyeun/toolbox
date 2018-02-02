require 'socket'
require 'json'

app = Proc.new do
  [ '200', 
    {'Content-Type' => 'text/html'}, 
    ["#{Time.now} : Unknown endpoint"]
  ]
end

server = TCPServer.new 5678

while session = server.accept
  request = session.gets
  puts request

  if ( request != nil )
	  method, full_path = request.split(' ')
    puts full_path

    status, headers, body = app.call({})
    session.print "HTTP/1.1 #{status}\r\n"

    headers.each do |key, value|
      session.print "#{key}: #{value}\r\n"
    end

    # Print a newline to seperate the status line, headers from the body
    session.print "\r\n"

		if( full_path == "/node" )
			result = `geth --exec 'admin.nodeInfo;' attach ipc://home/tanyeun/Program/blockChain/ethereum/node1/data/geth.ipc`
			result.gsub!(/([a-zA-Z0-9]+): /,'"\1": ')
			result.gsub!(/{...}/,'"\1"')
			data = JSON.parse(result)
		  new_data = {
				"enode" => data["enode"],
        "name" => data["name"]
      }
			session.print JSON[new_data]
    # Check if endpoint start with /block
    elsif ( /^\/block/.match(full_path) ) 
			block_number = full_path.gsub(/^\/block\//, '')
      if( block_number.include? "/" )
				session.print "Invalid block number specified"
				next
			else
				result = `geth --exec 'eth.getBlock(#{block_number});' attach ipc://home/tanyeun/Program/blockChain/ethereum/node1/data/geth.ipc`
				if( result == "null\n" )
				  session.print "Block out of range"
				  next
				else
			    result.gsub!(/([a-zA-Z0-9]+): /,'"\1": ')
			    result.gsub!(/{...}/,'"\1"')
			    data = JSON.parse(result)
		      new_data = {
			    	"difficulty" => data["difficulty"],
            "gasLimit" => data["gasLimit"],
						"gasUsed" => data["gasUsed"], 
						"hash" => data["hash"], 
						"miner" => data["miner"], 
						"parentHash" => data["parentHash"], 
						"totalDifficulty" => data["totalDifficulty"]
          }
			    session.print JSON[new_data]
				end
 			end
    elsif ( /^\/transaction/.match(full_path) ) 
			trans_hash = full_path.gsub(/^\/transaction\//, '')
      if( (trans_hash.include? "/") || (!trans_hash.include? "0x") || (trans_hash.length != 66) )
				session.print "Invalid format specified for transaction endpoint"
				next
			else
				result = `geth --exec 'eth.getTransaction("#{trans_hash}");' attach ipc://home/tanyeun/Program/blockChain/ethereum/node1/data/geth.ipc`
				if( result == "null\n" )
				  session.print "No transaction found"
				  next
				else
			    result.gsub!(/([a-zA-Z0-9]+): /,'"\1": ')
			    result.gsub!(/{...}/,'"\1"')
			    data = JSON.parse(result)
		      new_data = {
			    	"blockHash" => data["blockHash"],
            "blockNumber" => data["blockNumber"],
						"from" => data["from"], 
						"gas" => data["gas"], 
						"gasPrice" => data["gasPrice"], 
						"hash" => data["hash"], 
						"nonce" => data["nonce"],
						"to" => data["to"],
						"value" => data["value"]
          }
			    session.print JSON[new_data]
				end
 			end
		else
      # Print the body
      body.each do |part|
        session.print part
      end
    end
  end 
  session.close
end
