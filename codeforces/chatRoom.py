str = input()
def checkHello(): 
    i = 0
    while(str[i]!='h'):
        i+=1
        if(i == len(str)):
            print("NO")
            return
    
    while(str[i]!='e'):
        i+=1
        if(i == len(str)):
            print("NO")
            return
    while(str[i]!='l'):
        i+=1
        if(i == len(str)):
            print("NO")
            return
    while(str[i]!='l'):
        i+=1
        if(i == len(str)):
            print("NO")
            return
    while(str[i]!='0'):
        i+=1
        if(i == len(str)):
            print("NO")
            return
    print("YES")
    return
checkHello()
