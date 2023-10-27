# Directory Structure:

## Kerberos
The Kerberos protocol is commonly seen in instances where a target computer is configured and joined to a domain, where it reaches out to the Domain Controller (DC) to request service tickets for different services. 

## SMB
Server Message Block (SMB) protocol is commonly utilized for remote file sharing and in some instances authentication.

## NTLM
The New Technology LAN Manager (NTLM) protocol is a much older authentication protocol that is not commonly used today. This can be utilized in scenarios where the target computer is joined to a domain or hashes of the user password are stored locally within the Security Account Manager (SAM) database. 

## DCOM
The Distributed Component Object Model (DCOM) protocol is a protocol for exposing application objects via Remote Procedure Calls (RPCs). This protocol can be quite messy but also incredibly useful if aiming to remotely interact with a target computer given the proper credentials/authentication. 
