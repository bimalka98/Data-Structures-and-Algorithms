def findServerCount(timeLst):
    servers = []
    for i in range(len(timeLst)-1):
        found = False
        for serverIndex in range(len(servers)):
            if(servers[serverIndex] <= timeLst[i][:4]):
                servers[serverIndex] = getFreeTime(timeLst[i][-4:])
                found = True
                break
        if(not found):
            servers.append(getFreeTime(timeLst[i][-4:]))
    print(len(servers))        

def getFreeTime(time):
    newMinute = time[-2:]
    newHour = time[:2]
    if(int(time[-2:]) >= 55):
        newMinute = (int(time[-2:])+5)%60
        newHour = int(time[:2])+1
    else:
        newMinute = (int(time[-2:])+5)
    newMinute =  "0"*(2-len(str(newMinute)))+ str(newMinute)
    newHour = "0"*(2-len(str(newHour))) + str(newHour)
    return newHour+newMinute

def removeWhiteSpace(time):
    filteredTime = ""
    for letter in time:
        if(ord(letter)!= 32):
            filteredTime += letter
    return filteredTime


n = int(input())
timeLst = [];
for i in range(n):
    timeRange = input()
    timeRange.replace(" ","") 
    timeLst.append(removeWhiteSpace(timeRange).strip())


timeLst.sort()
findServerCount(timeLst)
    
