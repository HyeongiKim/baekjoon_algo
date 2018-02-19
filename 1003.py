def fibonacci(n):
    if n == 0:
        return [0]
    elif n == 1:
        return [1]
    else:
        return fibonacci(n-1) + fibonacci(n-2)

lines = input()
fibo = []
for i in range(lines):
    fibo.append(fibonacci(input()))

print '\n'.join("%d %d" % (e.count(0), e.count(1)) for e in fibo)

#for i in range(lines):
#    print "%d %d" % (fibo[i].count(0), fibo[i].count(1))
