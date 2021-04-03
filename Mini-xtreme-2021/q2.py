#Teacher and his Students
queries = int(input().strip())  #number of test cases
for query in range(queries):
    n,m = input().strip().split(' ')
    n,m = [int(n),int(m)]
    candies = list(map(int, input().strip().split(' ')))
    outclass=candies[n:]
    inclass=set(candies[:n])
    for student in outclass:
        if student in inclass:
            print ("YES")
        else:
            print ("NO")
            inclass.add(student)
