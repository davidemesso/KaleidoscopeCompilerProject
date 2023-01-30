def func(x)
    while x < 10
    in
        x = x + 1   :
        print(x)    
    end
;

def main()
    var x
    in
        while x < 10
        in
            print(x = x + 1)
        end :
        func(x)
    end 
;
