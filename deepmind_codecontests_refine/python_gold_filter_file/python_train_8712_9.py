l = ['purple','green','blue','orange','red','yellow']
dic = {'purple':"Power",'green':"Time",'blue':"Space","orange":"Soul",'yellow':"Mind",'red':"Reality"}
for _ in range(int(input())):
    stone = input()
    l.remove(stone)
print(len(l))
for i in l:
    print(dic[i])