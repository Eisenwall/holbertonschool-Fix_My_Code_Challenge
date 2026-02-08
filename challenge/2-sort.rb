#!/usr/bin/env ruby

result = []
ARGV.each do |arg|
    # Skip if not an integer
    next if arg !~ /^-?[0-9]+$/

    # Convert to integer and add to the array
    result << arg.to_i
end

# Sort the array numerically and print each element
puts result.sort
