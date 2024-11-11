import sys
no_of_letters = int(sys.stdin.readline().rstrip("\n"))
string = sys.stdin.readline().rstrip("\n")
string = [char for char in string]
new_string = []
vowels = ["a","e","i","o","u"]
offset = 0
for i in range(1,no_of_letters):
    if string[i-offset] in vowels and string[i-1-offset] in vowels:
        del(string[i-offset])
        offset+=1
    
            
print("".join(string))
