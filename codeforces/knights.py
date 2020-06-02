nm = []
for i in range(2):
    a = input()
    nm.append(a)
n = nm[0]
m = nm[1]
n = int(n)
m = int(m)
output = []
for i in range(n):
    output.append(0)

for i in range(m):
    a = input()
    b = input()
    c = input()
    for i in range(a, b+1):
        if(output[i] == 0):
            if(i != c):
                output[i] = c
            else:
                output[i] = 0
output.pop(0)
for i in range(n):
    print(output[i], " "),


