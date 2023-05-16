def binary_search(start, end):
    if (evaluate(start)):
        return start
    elif (not evaluate(end)):
        return False
    else:
        i=start
        j=end
        while True:
            if (j-i<=1):
                return j             
            else:
                new_=(j+i)//2
                if (evaluate(new_)):
                    j=new_
                else:
                    i=new_
    
    #used for cases where you have FFFTTT...