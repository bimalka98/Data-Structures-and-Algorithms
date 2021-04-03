t=int(input())
while(t>0):
    t-=1
    INF = 1000000000
    c = list(map(int,input().split()))
    while 1==1:
        reduced = False
        for a in range(10):
            for b in range(a,10):
                d = (a + b) % 10
                if c[d] > c[a] + c[b]:
                    reduced = True
                    c[d] = c[a] + c[b]
        if not reduced:
            break
    le = int(input())
    #print(c)
    s=input()
    tot = 0
    for i in s:
        tot += c[ord(i)-48]
    print(tot)
