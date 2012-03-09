EventMachine.run do
  urls.each do |url|
    uri = URI.parse(url)
    puts "Making Event Machine for #{uri.host}:#{uri.port}"
    c = EventMachine::Protocols::HttpClient.request(:host => uri.host, :port => uri.port,:request => uri.request_uri)
    c.callback {
      puts "Success"
    }
    c.errback {
      puts "Failure"
    } # necessary, otherwise a failure blocks the test suite forever.
    break
  end
end
