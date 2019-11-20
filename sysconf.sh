printf "Currently logged in user: "
whoami
echo "Current shell: $SHELL"
echo "Home directory: $HOME"
echo "Operating System type: $OSTYPE"
echo "Current path setting: $PATH"
printf "All shells: "
cat /etc/shells
printf "Current working directory: "
pwd
