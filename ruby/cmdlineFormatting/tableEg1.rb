require 'command_line_reporter'

class Example
  include CommandLineReporter

  def run
    table(:border => true) do
     row do
       column('NAME', :width => 20)
       column('ADDRESS', :width => 30, :align => 'right', :padding => 5)
       column('CITY', :width => 15)
     end
     row do
       column('Caesar')
       column('1 Appian Way')
       column('Rome')
     end
     row do
       column('Richard Feynman')
       column('1 Golden Gate')
       column('Quantum Field')
     end
   end
  end
end

Example.new.run
