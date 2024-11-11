friends = ["Danil", "Olya", "Slava", "Ann" , "Nikita"]
string = input()
count = [friend for friend in friends if friend in string]
if len(count) == 1:
    string = string.replace(count[0],' ',1)
    if count[0] in string:
        count.append(count[0])
    
output = 'Yes' if len(count)==1 else 'No'
print(output)