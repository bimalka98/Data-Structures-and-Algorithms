# Minimizing Cost 1
t=int(input())
for i in range(t):
    INF = 1000000000
    costs = list(map(int,input().split()))
    while True:
        reduced = False
        for a in range(10):
            for b in range(a,10):
                d = (a + b) % 10
                if costs[d] > costs[a] + costs[b]:
                    reduced = True
                    costs[d] = costs[a] + costs[b]
        if not reduced:
            break
    le = int(input())
    #print(costs)
    s=input()
    total = 0
    for i in s:
        total += costs[int(i)]
    print(total
