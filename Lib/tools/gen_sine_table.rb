#
#  gen_sine_table.rb
#
#  Created by Judah Menter on 10/8/09.
#  Copyright (c) 2009 __MyCompanyName__. All rights reserved.
#

tableSize = 2048;
outFileName = 'sinetable.h';
table = [];

if (ARGV.size > 0)
	tableSize = ARGV[0].to_i;
end

puts "Creating sine table of #{tableSize} samples...";

# Build sine table array
(0...tableSize).each do |i|
	table << Math.sin(2*Math::PI * (i.to_f/tableSize));
end

outFile = File.open(outFileName, 'w');

outFile << "#ifndef SINETABLE_H\n";
outFile << "#define SINETABLE_H\n\n";
outFile << "#define SINE_TABLE_SIZE #{tableSize}\n\n";

# Write main sine table
outFile << "const float sine[] = {\n\t";
(0...tableSize).each do |i|
	outFile << table[i].to_s << 'f';
	outFile  << ', ' unless i == tableSize - 1;
	outFile << "\n\t" if ((i + 1) % 5 == 0);
end
outFile << "};\n\n";

# Write sine delta table
outFile << "const float dsine[] = {\n\t";
(0...tableSize).each do |i|
	val = 0;
	if i < tableSize - 1
		val = table[i + 1] - table[i];
	else
		val = table[0] - table[i];
	end
	outFile << val.to_s << 'f';
	outFile  << ', ' unless i == tableSize - 1;
	outFile << "\n\t" if ((i + 1) % 5 == 0);
end
outFile << "};\n\n";

outFile << "#endif  /* SINETABLE_H */\n";

outFile.close;

