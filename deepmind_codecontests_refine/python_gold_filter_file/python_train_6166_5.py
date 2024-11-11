def reverse(s):
    return s[::-1]

def isPalindrome(s):
    # Calling reverse function
    rev = reverse(s)

    # Checking if both string are equal or not
    if (s == rev):
        return True
    return False


num, n= map(int, input().split())

l=[]
l2=[]
for i in range(num):
    l.append(input())

pals=""
rests=""

for x in l:
    if isPalindrome(x):
        pals=x
        l2.append(x)

    rex= reverse(x)
    if rex in l and rex not in l2:
        rests+=x
        l2.append(x)
        l2.append(rex)


print(len(pals)+2*len(rests))
print(rests+pals+reverse(rests))