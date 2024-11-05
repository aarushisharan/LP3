//SPDX-License-Identifier:MIT
pragma solidity ^0.8.0;

contract Bank{

    address public accHolder;
    uint256 public balance=0;

    //0xDA0bab807633f07f013f94DD0E6A4F96F8742B53

    constructor()
    {
        accHolder=msg.sender;//whoever deploys the contract becomes the manager 
    }

    function withdraw() payable public
    {
        require(balance>0,"You don't have enough balance");
        require(msg.sender==accHolder,"You are not the account owner");
        payable(msg.sender).transfer(balance);
        balance=0;

    }

    function deposit() public payable
    {
         
        require(msg.value>0, "Deposit amount should be greater than 0");
        require(msg.sender==accHolder,"You are not the account owner");
        balance+=msg.value;


    }

    function showBalance() public view returns(uint)
    {
        require(msg.sender==accHolder,"You are not the account owner");
        return balance;
    }
}
