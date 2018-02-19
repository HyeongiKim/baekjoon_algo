n = input()
costs = []

for i in range(n):
    costs.append(map(int, raw_input().split()))

R = 0
G = 1
B = 2

#n = 3
#costs = [[26, 40, 83], [49, 60, 57], [13, 89, 99]]
D = costs
for house in range(1,n):
    D[house][R] = min(D[house-1][G],D[house-1][B]) + costs[house][R]
    D[house][G] = min(D[house-1][R],D[house-1][B]) + costs[house][G]
    D[house][B] = min(D[house-1][R],D[house-1][G]) + costs[house][B]

print min(D[-1])
