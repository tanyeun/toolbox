require 'command_line_reporter'

# Note that 'progress' in init actually need to match
# with the progress statement inside the 10.times loop
# I added a sleep statements in so that it's easier to 
# observe how powerful this gem is and YES. It is 
# showing the progress of the 10.times loop
# After it finises, it will show a vertical spacing line
# and them display the result, which is Sum: 100 here
class Example
  include CommandLineReporter

  def initialize
    self.formatter = 'progress'
  end

  def run
    report do
      sum = 0
      10.times do
        sum += 10
        sleep(1)
        progress
      end
      vertical_spacing
      aligned("Sum: #{sum}")
    end
  end
end

Example.new.run
