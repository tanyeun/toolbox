require 'socket'

server = TCPServer.new 5678

while session = server.accept
  request = session.gets
  puts request

  session.print "HTTP/1.1 200\r\n"                      # Status line: Protocal & Response status to the browser
  session.print "Content-Type: text/html\r\n"           # Header: Indicate the response content type
  session.print "\r\n"    
  session.print "Hello world! The time is #{Time.now}"  # The message body 

  session.close
end
