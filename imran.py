import itertools
import os

for test in [' '.join(str(i) for i in p) for p in itertools.permutations([1,2,3])]:
	str = "./push_swap '" + test + "' | wc -l"
	print(str)
	os.system(str)
	str = "./push_swap '" + test + "' | ./checker_linux " + test
	os.system(str)