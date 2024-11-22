# Defina os diretórios local e remoto
$PastaLocal = "."
$PastaRemota = "/home/rasp/Documents/ifb_cg/"
$UsuarioRemoto = "rasp"
$HostRemoto = "rasp"   # ou IP

# Verificar se a pasta local existe
if (-Not (Test-Path ${PastaLocal})) {
    Write-Host "A pasta local '${PastaLocal}' nao existe."
    exit 1
}

# Apagar o conteúdo da pasta remota
Write-Host "Removendo o conteudo da pasta remota..."
ssh "${UsuarioRemoto}@${HostRemoto}" "rm -rf ${PastaRemota}/*"
if ($LASTEXITCODE -ne 0){
    Write-Host "Erro ao remover o conteúdo da pasta remota."
    exit 2
}

# Copiar o conteúdo da pasta local para a remota
Write-Host "Copiando o conteudo da pasta local para a remota..."
scp -r "${PastaLocal}\*" "${UsuarioRemoto}@${HostRemoto}:${PastaRemota}/"

# Verificar se a operação foi bem-sucedida
if ($LASTEXITCODE -eq 0) {
    Write-Host "Conteudo copiado com sucesso para a pasta remota."
} else {
    Write-Host "Erro ao copiar o conteudo para a pasta remota."
    exit 3
}
