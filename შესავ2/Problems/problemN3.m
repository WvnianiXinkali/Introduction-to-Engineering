%%a.
aMat = zeros(9) + 2;
aMat1 = ones(9) * 2;

%% b.
vec = [1, 2, 3, 4, 5, 4, 3, 2, 1];
bMat = diag(vec, 0);

%%c.
A = 1:100;
cMat = reshape(A, [10,10]);

%%d.
dMat = NaN([3, 4]);

%%e.
eMat = [[13, - 1, 5]; [-22, 10, -87]];

%%f.
fMat = floor((rand(5, 3) - 0.5) * 6);
fMat1 = randi(7,5,3) - 4;

