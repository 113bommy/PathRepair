s=str(input())
a=len(s)
def is_palindrome(s):
    for i in range(a//2):
        if(s[i]!=s[a-i-1]):
            return False
    return True
if(is_palindrome(s) and len(set(s))!=1):
    print(a-1)
elif(len(set(s))==1):
    print("-1")
else:
    print(a)
        