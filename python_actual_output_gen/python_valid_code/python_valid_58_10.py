n = int(input());
counter = 0;
for i in range( 0 , n ):
    string = input("");
    if string.count('--') >= 1:
        counter += 1;
    elif string.count('++') >= 1 :
        counter -= 1;
print (counter);
