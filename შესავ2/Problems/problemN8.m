
findNearest([[1, 2, 3, 4, 5, -1, -2, -7, 4], [1, 2, 3, 4, 5, -1, -2, -7, 4]], 4)
findNearest([1, 2, 3, 4, 5, -1, -2, -7, 4], 4)
function ind = findNearest(x, desiredVal)
    temp = x(:);
    temp = temp - desiredVal; %% 1 2 3 -2 -4  
    temp = abs(temp);
    tempvalue = min(temp);
    ind = find(tempvalue == temp);
end

