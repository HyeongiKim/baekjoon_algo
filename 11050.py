def binomial(n,k):
    if k == 0 or k == n:
        return 1
    if k < 0:
        return 0
    if k > n:
        return 0
    else:
        return binomial(n-1,k) + binomial(n-1,k-1)

n, k = map(int, raw_input().split())
print binomial(n,k)
