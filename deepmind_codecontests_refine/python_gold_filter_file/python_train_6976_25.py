def bubble(c):
	for i in range(len(c)):
		for j in range(len(c)-1,i,-1):
			if int(c[j][-1]) < int(c[j-1][-1]):
				c[j],c[j-1] = c[j-1],c[j]
	return c

def selection(c):
	for i in range(len(c)):
		mini = i
		for j in range(i,len(c)):
			if int(c[j][-1])<int(c[mini][-1]):
				mini = j
		c[i],c[mini]=c[mini],c[i]
	return c

n = int(input())
card = list(map(str,input().split()))
card1 = card[:]
bubble(card)
selection(card1)
print(" ".join(map(str,card)))
print("Stable")
print(" ".join(map(str,card1)))
print("Stable") if card==card1 else print("Not stable")