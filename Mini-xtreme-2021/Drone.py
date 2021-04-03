def check_order(dest, order):
    
    countL=0
    countR=0
    countU=0
    countD=0
    for i in order:
        if i=='L':
            countL+=1
        
        if i=='R':
            countR+=1
        
        if i=='U':
            countU+=1
        
        if i=='D':
            countD+=1
        
    # print("CountD = ",countD)
    # print("CountU = ",countU)
    # print("CountL = ",countL)
    # print("CountR = ",countR)

    status = True     

    if dest[0]<0:
        if (countL<abs(dest[0])):
            status = False
        # print(status)
    elif dest[0]>0:
        if (countR<dest[0]):
            status = False
        # print(status)
    if dest[1]<0:
        if (countD<abs(dest[1])):
            status = False
        # print(status)
    elif dest[1]>0:
        if (countU<dest[1]):
            status = False
        # print(status)
    
    if status:
        print("YES")
    else:
        print("NO")

queries=int(input())

for i in range (0,queries):
    dest = list(map(int, input().split()))
    order = input()
    check_order(dest, order)
