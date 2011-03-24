#  Created by Judah Menter on 10/8/09.
#  Copyright (c) 2009 __MyCompanyName__. All rights reserved.
#

minCutoff = 100
maxCutoff = 11025
tableSize = maxCutoff - minCutoff + 1;
outFileName = 'CutoffTable.h';
table = [];

if (ARGV.size > 0)
	tableSize = ARGV[0].to_i;
end

puts "Creating cutoff table of #{tableSize} samples...";

# Build table array
(0...tableSize).each do |i|
	freq = i + minCutoff
	table << ( 1.0 / Math.tan(Math::PI * freq.to_f / 44100.0) );
end

outFile = File.open(outFileName, 'w');

outFile << "#ifndef CUTOFFTABLE_H\n";
outFile << "#define CUTOFFTABLE_H\n\n";
outFile << "#define CUTOFF_TABLE_SIZE #{tableSize}\n\n";
outFile << "#define CUTOFF_MIN #{minCutoff}\n\n";
outFile << "#define CUTOFF_MAX #{maxCutoff}\n\n";

# Write main sine table
outFile << "const float CutoffTable[#{tableSize}] = {\n\t";
(0...tableSize).each do |i|
	outFile << table[i].to_s << 'f';
	outFile  << ', ' unless i == tableSize - 1;
	outFile << "\n\t" if ((i + 1) % 5 == 0);
end
outFile << "};\n\n";

outFile << "#endif  /* CUTOFFTABLE_H */\n";

outFile.close;

