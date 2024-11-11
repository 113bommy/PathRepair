from collections import Counter
def isSubsequence(s,t):
    idx = 0
    for i in s:
        if idx==len(t):
            return True
        if i==t[idx]:
            idx+=1
    return True if idx>=len(t) else False
s = input()
t = input()
#automaton - delete characters
#array - swap two characters
#need tree -  not possible using automaton and array
if sorted(s)==sorted(t):
    print("array")
elif isSubsequence(s,t):
    print("automaton")
else:
    counter1 = Counter(s)
    counter2 = Counter(t)
    for i in counter2:
        if counter2[i]!=counter1[i]:
            print("need tree")
            break
    else:
        print("both")
