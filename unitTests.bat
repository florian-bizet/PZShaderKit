gcc export.c -o export.exe

echo "TEST 1 : No Args"
.\export.exe

echo "TEST 2 : Missing File"
.\export.exe panzoid.glsl

echo "TEST 3 : Valid file"
.\export.exe shader.glsl