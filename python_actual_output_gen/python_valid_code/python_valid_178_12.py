letters="abcdefghijklmnopqrstuvwxyz"
letterlist=[]
letterlist.extend(letters)
N=int(input(""))
word=input("")
def pangram(word,letterlist):
    for i in letterlist:
        if i not in word:
            return False
    return True
if pangram(word,letterlist):
    print("YES")
else:
    print("NO")

