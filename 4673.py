def d(n):
    num = str(n)
    for i in num:
        n = n + int(i)
    return n

a = range(1,10000)

for i in range(1,10000):
    out_d = d(i)
    if out_d in a:
        a.remove(out_d)

for num in a:
    print num

