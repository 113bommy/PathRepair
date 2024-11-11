def bracket():
    s=str(input())
    c=0;
    b=0;
    for i in range (len(s)):
        if( s[i]=='('):
            c+=1;
        elif (s[i]==')'):
            c-=1;
            if (c>=0):
                b+=2;
            elif (c<0):
                c=0;
    print(c);

bracket()