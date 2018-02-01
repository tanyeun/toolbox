require 'socket'

server = TCPServer.new 5678

while session = server.accept
  session.puts "Hello World! The time is #{Time.now}"
  session.close
end
