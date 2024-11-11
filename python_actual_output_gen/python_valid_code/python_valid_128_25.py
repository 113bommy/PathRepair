s=input()
print("YES") if(len([x for x in s if x in ['H', 'Q', '9', '+']])>0) else print("NO")
