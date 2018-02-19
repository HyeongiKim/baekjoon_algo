def f(s):
    if len(s) >=2:
        s.append(s[-1] + s[-2])
        return s

fibo = [0, 1]
n = input()

if n <=1:
    print fibo[n]
else:
    for i in range(2,n+1):
        fibo = f(fibo)
    print fibo[n]
