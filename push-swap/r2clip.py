#run this progam to get a bunch of numbers copied to your clipboard
#Usage: python3 r2clip.py {Number of Integers} {Lowest Value} {Highest Value}
import random
import sys
import subprocess

x, a, b = map(int, sys.argv[1:4])
numbers = random.sample(range(a, b+1), x)
output = " ".join(str(num) for num in numbers)

process = subprocess.Popen(['pbcopy'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
process.communicate(input=output.encode('utf-8'))
