def binary_search(start, end, find):
    if (find < l[start]):
        return n
    elif (find >= l[end]):
        return -1
    else:
        i=start
        j=end
        while True:
            if (j-i<=1):
                return j     #if you want to return smaller-closest or bigger-closest, make changes here 
            else:
                new_=(j+i)//2
                if (eval(new_)==find):
                    return new_
                elif (eval(new_)>find):
                    j=new_
                else:
                    i=new_