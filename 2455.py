train = 0
num = []
for i in range(4):
    OUT,IN = map(int, raw_input().split())
    train = train + (IN - OUT)
    num.append(train)
print max(num)
