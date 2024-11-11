string = ''
for i in range(1, 10000):
    a = str(i)
    string = string + a
    
num = int(input())

s = list(string)

print(s[num-1])