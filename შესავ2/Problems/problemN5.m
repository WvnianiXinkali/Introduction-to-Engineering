%%a.
A = 1:100;
cMat = reshape(A, [10,10]);
cSum = sum(cMat);
%%b.
eMat = [[13, - 1, 5]; [-22, 10, -87]];
eMean = mean(eMat, 2);
%%c.
change = [1, 1, 1];
eMat(1,:) = change;
%%d.
cSub = cMat(2:9, 2:9);
%%e.
lin = [1:20];
for c = lin
    p = (-1)^lin(c);
    if  p == 1
        k = lin(c);
        lin(c) = -1 * k;
    end
end
lin
%%f.
vec = rand(1,5);
q = find(vec < 0.5);
for o = q
    vec(o) = 0;
end
vec
