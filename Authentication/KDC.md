# Key Distribution Center (KDC)

## A Brief History

## How it Works
The KDC functions as a domain service. It operates as a single process that offers two services: 

  1) Authentication Service - This service issues Ticket-Granting Tickets (TGTs) for use with the Ticket Granting Service (TGS), which allows users to make specific requests to services within the domain. The user must request a TGT for the target domain the requested target service is in. The TGT can be used until expiration, but prior to contacting the TGS for the first time every client must contact the authentication service to obtain a TGT. 
  2) Ticket Granting Service (TGS) - This service provides tickets for targets within their own domain. Prior to accessing a computer for the first time, the user must present the TGS with a TGT and request a ticket for the service on the target computer. 

The KDC resides on the domain controller along with the Active Directory. Both services are started automatically by the domain controller's LSA upon start and run within the LSA process.

The security principal name used by the KDC in any domain is 'krbtgt'. An account for this security principal is automatically created upon the creation of the domain. The account cannot be created, nor can it be deleted. A random password value is assigned to the account automatically by the system during the creation of the domain. The password for the KDC's account is used to derive a cryptographic key for encrypting and decrypting the TGTs that it issues. The password for a domain trust account is used to derive an inter-realm key for encrypting referral tickets.

## Sources:
- https://learn.microsoft.com/en-us/windows/win32/secauthn/key-distribution-center
  