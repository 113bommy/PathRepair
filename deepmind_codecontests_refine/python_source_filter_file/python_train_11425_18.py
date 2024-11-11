def reverse(string): 
    string1 = string[::-1] 
    return string1
n = 0
string = input()
s1 = reverse(string)
if s1 == string:
    y = len(string)
    for i in range(0,y):
        for j in range(0,y):
            if string[i] == s1[j]:
                n=n+1
                print(n)
    y =len(string)
    z = y*y
    if n==z:
        print("0")
    else:
        y = len(string)-1
        print(y)
else:
    print(len(string))
   
