import random
import sys


number = 100
try:
    number = int(sys.argv[1])
except:
    pass

f = open(f'numbers{str(number)}.txt','w')
for i in range(number):
    f.write(str(random.randint(0,1000)) + ' ')

f.close()