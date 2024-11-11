a,g,a_,a__,ac,ga,al=[0]*6+[1]
for i in range(int(input())):
    a__,a_,ac,ga,a,g,al=a_,a,a-ga,g,al,al-ac,(al*4-(a_+ac+ga+a__*3))%(pow(10,9)+7)
print(al)
