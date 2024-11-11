ss1 = input()
ss2 = input()

vowels = ['a', 'e', 'i', 'o', 'u']

def CanTransform(s1, s2):
    if len(s1)!=len(s2):
        return "No"
    else:
        for i in range(len(s1)):
            if s1[i]!=s2[i] and ((s1[i] in vowels and s2[i] not in vowels) or (s1[i] not in vowels and s2[i] in vowels)):
                return "No"
    return "Yes"
	
CanTransform(ss1, ss2)