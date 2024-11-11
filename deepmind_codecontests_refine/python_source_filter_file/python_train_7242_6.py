input = input()
input = list(input)
#"lasar"
dictBulb = {"B":1,"u":2,"b":1,"l":1,"a":2,"s":1,"r":1}
dict = {}
setb = set("Bulbasaur")
for letter in list(setb):
	dict[letter] = 0
	
for letter in input:
	if letter in setb:
		dict[letter] += 1

dict['u'] = dict['u']/2
dict['a'] = dict['a']/2

print (min(dict.values()))