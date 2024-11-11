while True:
    [h, w] = map(int, (input().split()))
    if h==0 and w==0:
        break
    else:   
        print("#"*w+"\n"+("#"+"."*(w-2)+"#\n")*(h-2)+"#"*w)