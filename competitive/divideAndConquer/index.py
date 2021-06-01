import json
import sys

args = sys.argv
print(args)


file = json.load(open(args[1],))

for key in file:
    if key.id in args[2]:
        sum += key.count
print(sum)
