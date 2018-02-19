import math

def getPrime(num):
    if num == 1:
        return 0
    elif num == 2:
        return 1
    else:
        for x in range(2, num):
            if num % x == 0:
                return 0
            elif x > math.sqrt(num):
                return 1
n = input()
numbers = map(int, raw_input().split())
print sum (map(getPrime, numbers))    
