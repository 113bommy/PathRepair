#Superhero Transformation
vowels = ['a','e','i','o','u']

heroa = input()
herob = input()

if len(heroa) != len(herob): print("No")
else:
    for i in range(1,len(heroa)):
        if (heroa[i] in vowels) != (herob[i] in vowels): 
            print("No")
            quit()
    print("Yes")