# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure(2) do |config|
  config.vm.define "kali", primary: true do |kali|
	kali.vm.network "private_network", type: "dhcp", auto_config: false
	kali.vm.box = "starflame/kali2_linux4.0.0_amd64"
  end
  config.vm.define "metasploitable" do |metasploitable|
    metasploitable.ssh.username =  "msfadmin"
    metasploitable.ssh.password = "msfadmin"
	metasploitable.vm.synced_folder "src/", "/vagrant", disabled: true
	metasploitable.vm.network "private_network", type: "dhcp", auto_config: false
	metasploitable.vm.box = "plecuyer/cr210-pentest-linux"
  end
end
