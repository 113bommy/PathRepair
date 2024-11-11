print ("Enter the given text")
text = input()
word = "CODEFORCES"

# First check to see if the length even works
if len(text) <= 10:
    print ("NO")
elif text[0:10] == "CODEFORCES":  # At the beginning
    print("YES")
elif text[len(text)-10:] == "CODEFORCES":  # At the end
    print("YES")
else:
    found = False
    for i in range(1,10):    # Number of letters at the start
        if text[0:i] == word[0:i] and text[len(text)-(10-i):] == word[i:]:
            print("YES")
            found = True
            break
    if found == False:
        print("NO")
