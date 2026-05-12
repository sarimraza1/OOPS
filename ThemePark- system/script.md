# Encryption Presentation Script

**Presenter:** Sarim

AOA everyone, My name is Sarim, and today I’m going to walk you through something that we use heavily and rely on in our daily lives.

Have you ever wondered whether the data you send—like text, audio, video, or documents—to a friend or anyone else is really safe and remains only between you two?

The answer is both yes and no. The data you send can be intercepted and stolen by hackers, who may use it for their own benefit.

This is where encryption comes in. Encryption cannot prevent data from being stolen, but it makes the data useless for the hacker.

As you can see in this example: The first image contains a message you would send to a friend. Before being transmitted over the internet to the receiver, it is encrypted, which is shown in the middle image. Then, it is decrypted at the receiver’s end to show the original content.

Now, there are two types of encryption.

First, let’s talk about symmetric encryption. In this method, the system generates a shared key, which is used to both encrypt and decrypt the message. For example, if Ali wants to send a message to Sara, the same key is shared with both Ali and Sara, and it is used to encrypt and decrypt the message.

However, if you analyze it closely, there is a major flaw. The key needs to be shared before use. What if a hacker steals this key? They could then access your data. This problem is known as the key distribution problem.

This is where asymmetric encryption comes in. In this method, the system generates a pair of keys for each user:
- **A public key**, which is used to encrypt the message and is shared with everyone.
- **A private key**, which is used to decrypt the message and is kept secure by the owner.

For example, if Ali wants to send a message to Sara, he will use Sara’s public key to encrypt the message. The message is then transmitted over the internet, and Sara uses her private key to decrypt it. This successfully solves the key distribution problem.

In modern systems, a combination of symmetric and asymmetric encryption is used.

Encryption plays a key role in securing data during transmission. However, it cannot fully guarantee safety. If your device is compromised or infected with malicious software, encryption alone will not be enough.

In simple terms, encryption cannot prevent data from being stolen, but it prevents it from being used against your will.

That’s it. If you have any questions, feel free to ask. Thank you.
